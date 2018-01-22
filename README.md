A plugin to control a quadrotor(Iris) in Gazebo using a predictive control running in Simulink. ROS works as Comunication Layer.  
  
The plugin creates 2 topics:  
  
Publisher
/gazebo_client/iris_state  
Description: Publish the information from Iris Quadcopter, the Pose in the "Orientation Covariance" array, and the angular and linear velocity in the "angular_velocity_covariance" array.  
Message Type: sensor_msgs/Imu  
  
Subscriber  
/my_iris/vel_cmd  
Description: Topic to pubslish the desired velocity of the rotors.  
Message Type: geometry_msgs/Quaternion  
Pub command example: rostopic pub -- /my_iris/vel_cmd geometry_msgs/Quaternion 100 100 100 100

