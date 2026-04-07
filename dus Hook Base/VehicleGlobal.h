#pragma once



struct VehicleInfos {

	void* boardedVehicle;
	bool HasDriver;
	float Speed;
	bool IsStarted;
};

inline VehicleInfos g_Vehicle;
inline std::chrono::steady_clock::time_point v_LastUpdate;

namespace Vehicle {

	inline bool CustomTransform = false;
	inline float speedMultiplier = 1;

}