#ifndef _IRIS_PLUGIN_HH_
#define _IRIS_PLUGIN_HH_

#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/Float32.h"
#include <stdio.h>
#include <stdlib.h>
#include "std_msgs/Float32MultiArray.h"
#include </home/rech/catkin_ws/devel/include/msg_vel_rotors/vel_motors.h>


namespace gazebo
{
  /// \brief A plugin to control a Velodyne sensor.
  class IrisPlugin : public ModelPlugin
  {
    /// \brief Constructor
    public: IrisPlugin() {}

    /// \brief The load function is called by Gazebo when the plugin is
    /// inserted into simulation
    /// \param[in] _model A pointer to the model that this plugin is
    /// attached to.
    /// \param[in] _sdf A pointer to the plugin's SDF element.
    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
    {
    // Just output a message for now
    	std::cerr << "\nThe iris plugin is attach to model[" << _model->GetName() << "\n";
	
	// Store the model pointer for convenience.
	this->model = _model;	

	// Initialize ros, if it has not already bee initialized.
	if (!ros::isInitialized())
	{
	  int argc = 0;
	  char **argv = NULL;
	  ros::init(argc, argv, "gazebo_client", ros::init_options::NoSigintHandler);
	}

	// Create our ROS node. This acts in a similar manner to
	// the Gazebo node
	this->rosNode.reset(new ros::NodeHandle("gazebo_client"));

	// Create a named topic, and subscribe to it.
	ros::SubscribeOptions so = ros::SubscribeOptions::create<msg_vel_rotors::vel_motors>(
	"/" + this->model->GetName() + "/vel_cmd",1,
	 boost::bind(&IrisPlugin::OnRosMsg, this, _1), ros::VoidPtr(), &this->rosQueue);
	
	this->rosSub = this->rosNode->subscribe(so);

	// Spin up the queue helper thread.
	this->rosQueueThread = std::thread(std::bind(&IrisPlugin::QueueThread, this));

/*
	msg_vel_rotors::vel_motors testpub;
	testpub.data = {1, 2, 3, 4};
	//Test Publisher
	pub_.publish(testpub); // use publisher
	//ros::spinOnce();

	ros::AdvertiseOptions ao = ros::AdvertiseOptions::create<msg_vel_rotors::vel_motors>(
	"/teste_iris_pub", 1,
	boost::bind(&GazeboRosLaser::LaserConnect, this),
	boost::bind(&GazeboRosLaser::LaserDisconnect, this),
	ros::VoidPtr(), NULL);
	this->pub_ = this->rosnode_->advertise(ao);
	this->pub_queue_ = this->pmq.addPub<sensor_msgs::LaserScan>();
*/
	}



	public: void SetVelocity(double vel[4])
    {
	//std::cerr <<vel[0]<< "\n";
	//std::cout << "Funcao" << "\n"; 	
	this->model->GetJoints()[2]->SetVelocity(0, 1*vel[0]);
	this->model->GetJoints()[3]->SetVelocity(0, 1*vel[1]);
	this->model->GetJoints()[4]->SetVelocity(0, -1*vel[2]);
	this->model->GetJoints()[5]->SetVelocity(0, -1*vel[3]);
    }


	/// \brief Handle an incoming message from ROS
	/// \param[in] _msg A float value that is used to set the velocity
	/// of the Velodyne.
	public: void OnRosMsg(const msg_vel_rotors::vel_motorsConstPtr& msg)
	{
	std::cerr <<msg->data[0]<< "\n";
	std::cerr <<msg->data[1]<< "\n";
	std::cerr <<msg->data[2]<< "\n";
	std::cerr <<msg->data[3]<< "\n";
	double test[4] = { msg->data[0], msg->data[1], msg->data[2], msg->data[3]};
	this->SetVelocity(test);
	}

	/// \brief ROS helper function that processes messages
	private: void QueueThread()
	{
	  static const double timeout = 0.01;
	  while (this->rosNode->ok())
	  {
	    this->rosQueue.callAvailable(ros::WallDuration(timeout));
	  }
	}


	/// \brief A node used for transport
	private: transport::NodePtr node;

	/// \brief A subscriber to a named topic.
	private: transport::SubscriberPtr sub;

	/// \brief Pointer to the model.
	private: physics::ModelPtr model;

	/// \brief Pointer to the joint.
	private: physics::JointPtr joint;

	/// \brief A node use for ROS transport
	private: std::unique_ptr<ros::NodeHandle> rosNode;

	/// \brief A ROS subscriber
	private: ros::Subscriber rosSub;

	/// \brief A ROS callbackqueue that helps process messages
	private: ros::CallbackQueue rosQueue;

	/// \brief A thread the keeps running the rosQueue
	private: std::thread rosQueueThread;  


	//Test Pubros::SubscribeOptions::create
	//boost::shared_ptr<ros::NodeHandle> rosnode_;
	//msg_vel_rotors::vel_motors joint_state_;
	//ros::Publisher joint_state_publisher_;



	};

  // Tell Gazebo about this plugin, so that Gazebo can call Load on this plugin.
  GZ_REGISTER_MODEL_PLUGIN(IrisPlugin)
}
#endif
