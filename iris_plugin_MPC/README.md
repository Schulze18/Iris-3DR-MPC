A plugin to control a quadrotor (Iris 3DR) in Gazebo. A Model Predictive Controller (MPC) is implemented in the plugin with the code generated from Simulink.ROS works as Comunication Layer.

The plugin creates 3 topics:

Publisher  
/gazebo_client/iris_state  
Description: Publish the information from Iris Quadcopter, the Pose in the "Orientation Covariance" array, and the angular and linear velocity in the "angular_velocity_covariance" array.  
Message Type: sensor_msgs/Imu

Publisher  
/gazebo_client/vel_cmd  
Description: Publish the velocities calculated by the MPC and applied to the rotors.  
Message Type: geometry_msgs/Quaternion  


Subscriber  
/my_iris/iris_ref  
Description: Topic to pubslish the desired position of the quadrotor.  
Message Type: geometry_msgs/Point  
Pub command example: rostopic pub -- /my_iris/iris_ref geometry_msgs/Point 0 0 1  

After download all the files, go to the "iris_plugin_MPC" folder and do the following commands:  
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:~/iris_plugin/build  
mkdir build  
cd build  
cmake ..  
make
