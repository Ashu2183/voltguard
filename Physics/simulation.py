# simulation.py

from flow import FlowCalculator
from pressure import PressureCalculator


class PhysicsSimulation:
    def __init__(self):
        self.flow = FlowCalculator()
        self.pressure = PressureCalculator()

    def run(self, velocity):
        """
        Run physics simulation.
        """

        flow_rate = self.flow.calculate_flow_rate(velocity)
        pressure = self.pressure.calculate_pressure(velocity)

        flow_safe = self.flow.is_safe_flow(flow_rate)
        pressure_safe = self.pressure.is_safe_pressure(pressure)

        status = "SAFE"

        if not flow_safe or not pressure_safe:
            status = "UNSAFE"

        return {
            "velocity": velocity,
            "flow_rate": flow_rate,
            "pressure": pressure,
            "flow_safe": flow_safe,
            "pressure_safe": pressure_safe,
            "status": status
        }


def print_result(result):
    print("\n========== VoltGuard Physics Engine ==========")

    print(f"Velocity          : {result['velocity']} m/s")
    print(f"Flow Rate         : {result['flow_rate']} m³/s")
    print(f"Pressure          : {result['pressure']} Pa")

    print()

    print(f"Flow Status       : {'SAFE' if result['flow_safe'] else 'UNSAFE'}")
    print(f"Pressure Status   : {'SAFE' if result['pressure_safe'] else 'UNSAFE'}")

    print("----------------------------------------------")

    print(f"Overall Status    : {result['status']}")

    print("==============================================\n")


if __name__ == "__main__":

    simulator = PhysicsSimulation()

    # Test velocity (m/s)
    result = simulator.run(2.5)

    print_result(result)