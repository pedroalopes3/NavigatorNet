# Synthetic Swarm UWB Bags

Generated from: `rosbag2_2026_04_20-23_23_16`

## Configuration
| Parameter | Value |
|---|---|
| Source bag | `rosbag2_2026_04_20-23_23_16` |
| Swarm drones | 5 |
| Distance range | [2.0, 200.0] m |
| UWB noise σ | 0.3 m |
| Random seed | 42 |
| GPS samples | 867 |

## Topics per drone bag

| Topic | Type | Description |
|---|---|---|
| `/gps/fix` | `sensor_msgs/NavSatFix` | Ground-truth GPS of this drone |
| `/uwb/range_to_main` | `sensor_msgs/Range` | UWB distance to the main drone |
| `/uwb/range_to_swarm` | `std_msgs/Float32MultiArray` | UWB distances to all other swarm drones (index = drone number, NaN = self) |

## Consistency guarantees
- All cross-drone distances are computed from the **same generated positions**,
  so `/uwb/range_to_swarm[i]` on drone A equals `/uwb/range_to_main` on drone B
  (up to independent noise draws).
- Absolute distance from main drone is always within [2.0, 200.0] m.
- Trajectories are smooth (low-pass random walk, no teleportation).
- UWB range noise is Gaussian with σ = 0.3 m, independent per measurement.

## Distance stats
- Main-to-drone:  min=22.4 m  mean=116.4 m  max=200.0 m
- Cross-drone:    min=38.8 m  mean=179.4 m  max=321.9 m
