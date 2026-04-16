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

enum class Corner_type {
	Steady=1,
	Transient=2
};

enum class Corner_side {
	Right=1,
	Left=2
};

enum class Pedals_input {
	Braking = 1,
	Driving = 2,
	Coasting = 3,
	Cruising = 4,
	Custom = 5
};

enum class Steering_input {
	Steering = 1,
	Straight = 2,
	Custom = 3
};

enum class Arb_setup{
	one=1,
	two=2,
	three=3,
	four=4,
	five=5
};