# Velocity_Inverter
This package solves the issue with ignition gazebo where the robot moves in the opposite 
direction than what it is being tol to by the cmd_vel message

I solved this by subscribing to the cmd_vel message, multipling the X componet of the Linear vector by -0.25
and publishing it on a new message called /mammoth/cmd_vel

To get these changes to work in ignition gazebo, I had to change the cmd/vel remapping in the gazebo launch file 
