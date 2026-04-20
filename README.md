# Vehicle Dynamics Simulation Tool

This project implements a four-wheel quasi-steady-state vehicle dynamics simulation tool designed to support vehicle 
performance analysis and setup development. The software includes a graphical user interface (GUI) and a Yaw Moment 
Diagram (YMD) plotting tool for evaluating vehicle handling characteristics.

---

# Development Environment

The software is developed and maintained using the following environment:

* **IDE:** Visual Studio 2022
* **Programming Language:** C++
* **Framework:** .NET Framework 4.7.2
* **Platform:** Windows

The project must be opened and built using a Visual Studio installation that supports the .NET Framework 4.7.2 toolchain.

---

# Directory Structure

The project follows a simple directory organization.

Typical directory structure:

```
VehicleDynamics/

    Project1/
            Inputs.cpp
            Inputs.h
            MyForm.cpp
            MyForm.h
            Outputs.h
            Simulation_controller.cpp
            Simulation_controller.h
            State_variables.h
            Tire.cpp
            Tire.h
            Tire_list.txt
            Tire_Selection.cpp
            Tire_selection.h
            Vehicle.cpp
            Vehicle.h
            Vehicle_params_1.txt
            Vehicle_repository.h
            YMD.cpp
            YMD.h
            Tires/

    README
    VehicleDynamics.slnx

# Build Instructions

Follow these steps to build and run the software.

## Requirements

* Windows operating system
* Visual Studio 2022
* .NET Framework 4.7.2 installed
* C++ Desktop Development workload enabled

## Build Procedure

1. Clone or download the repository.

2. Open the solution file:

```
VehicleDynamics.slnx
```

3. Verify the project configuration:

* Target Framework: .NET Framework 4.7.2
* Platform: x64 or Win32
* Build Configuration: Debug or Release

4. Build the solution:

```
Build -> Build Solution
```

or press:

```
Ctrl + Shift + B
```

5. Run the application:

```
Debug -> Start Debugging
```

# Parameter Files

The simulation uses parameter .txt files to store vehicle and tire data. These files allow users to define reusable
vehicle setups without modifying the source code.

Tire parameter files are stored in the Tires/ directory. They hold the parameters that define each singular saved tire model,
like radius, stiffness and Pacejka parameters.

```
Tires/
    Tire1.txt
    Tire2.txt
```
Tire_list.txt holds the names of all saved tire models, so that the user can select them inside the UI.

Vehicle_params_1.txt holds all the information about the vehicle the software needs to run the simulations.
It also holds state variables that control simulation behavior, such as solver settings and operating conditions.

---

# Usage Summary

Typical workflow:

1. Open the solution in Visual Studio
2. Build the project
3. Launch the application
4. Load or create a vehicle configuration
5. Select tires and input simulation parameters
6. Run the simulation
7. Analyze outputs and generate Yaw Moment Diagrams (YMD)

---

# Intended Users

This software is designed for:

* Formula SAE (FSAE) team members
* Student engineers working on race car development

---

# Version

Version: 1.0

Last updated: 2026-04-20
