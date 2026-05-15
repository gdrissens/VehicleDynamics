#pragma once

enum class Actuator_type {
	Inboard=1,
	Outboard=2
};

enum class Actuator_config {
	All=1,
	Front=2,
	Rear=3
};

enum class Actuator_lock {
	Open=1,
	Geared=2,
	Ramp=3,
	Tracloc=4,
	Locked = 5
};

enum class Pedals_input {
	Braking = 1,
	Driving = 2,
	Coasting = 3,
	Cruising = 4,
};

enum class Steering_input {
	Steering = 1,
	Straight = 2,
};