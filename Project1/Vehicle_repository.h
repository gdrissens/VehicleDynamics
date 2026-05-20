#pragma once
#include <string>
#include "Inputs.h"

    class Vehicle_repository
    {
    public:
        static constexpr int CURRENT_VERSION = 1;

        void validate(const Vehicle_inputs& vehicle_inputs);

        void upgrade_version(Vehicle_inputs& vehicle_inputs);

    private:

        
    };


