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

enum class Arb_setup{
	one=1,
	two=2,
	three=3,
	four=4,
	five=5
};