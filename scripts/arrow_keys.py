import airsim
import sys, tty, termios

# --- SETTINGS ---
SPEED = 5.0   # Speed in m/s
YAW_RATE = 20 # Rotation speed in deg/s

msg = """
---------------------------
DRONE CONTROL (No ROS)
---------------------------
    Arrow Keys:  Move Forward/Back/Left/Right
    W / S:       Up / Down
    A / D:       Rotate Left / Right
    
    T:           Takeoff
    L:           Land
    SPACE:       STOP (Brake)
    Q:           Quit
---------------------------
"""

# Connect to AirSim
client = airsim.MultirotorClient()
client.confirmConnection()
client.enableApiControl(True)
print("Connected!")
print(msg)

def get_key():
    """Reads a single keypress without waiting for Enter"""
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(sys.stdin.fileno())
        ch = sys.stdin.read(1)
        if ch == '\x1b':  # Handle Arrow Keys
            ch = sys.stdin.read(2)
            if ch == '[A': return 'up'
            if ch == '[B': return 'down'
            if ch == '[C': return 'right'
            if ch == '[D': return 'left'
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return ch

# Initial State
vx, vy, vz = 0.0, 0.0, 0.0
yaw_speed = 0.0

try:
    while True:
        key = get_key()
        
        # Reset speeds (so it stops if you don't hold the key, optional logic)
        # Or keep momentum? Let's use momentum logic (press to add speed)
        
        if key == 't':
            print("Taking off...")
            client.armDisarm(True)
            client.takeoffAsync().join()
            
        elif key == 'l':
            print("Landing...")
            client.landAsync().join()
            client.armDisarm(False)
            
        elif key == ' ': # STOP
            vx, vy, vz, yaw_speed = 0, 0, 0, 0
            print("BRAKE!")

        elif key == 'q':
            break

        # Movement Logic
        elif key == 'up':    vx = SPEED
        elif key == 'down':  vx = -SPEED
        elif key == 'left':  vy = -SPEED
        elif key == 'right': vy = SPEED
        elif key == 'w':     vz = -SPEED # Up (Negative Z)
        elif key == 's':     vz = SPEED  # Down (Positive Z)
        elif key == 'a':     yaw_speed = -YAW_RATE
        elif key == 'd':     yaw_speed = YAW_RATE

        # Send Command to Drone
        # We send it for a short duration (0.5s) so if you stop typing, it eventually stops
        client.moveByVelocityBodyFrameAsync(
            vx, vy, vz, 
            0.1, 
            airsim.DrivetrainType.MaxDegreeOfFreedom, 
            airsim.YawMode(True, yaw_speed)
        ).join()

        # Reset velocity slightly to simulate friction (optional, removes "drift")
        vx, vy, vz, yaw_speed = 0, 0, 0, 0

except KeyboardInterrupt:
    pass
finally:
    # Stop drone on exit
    client.moveByVelocityAsync(0, 0, 0, 1).join()
    print("\nExiting...")