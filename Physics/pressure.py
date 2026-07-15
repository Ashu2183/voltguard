# pressure.py

from config import SIMULATION_CONFIG


class PressureCalculator:
    def __init__(self):
        self.water_density = SIMULATION_CONFIG["water_density"]

    def calculate_pressure(self, velocity):
        """
        Calculate dynamic pressure (Pa)

        Formula:
            P = 0.5 × ρ × v²
        """

        pressure = 0.5 * self.water_density * (velocity ** 2)

        return round(pressure, 2)

    def is_safe_pressure(self, pressure):
        """
        Check if pressure is within safe operating limits.
        """

        min_pressure = SIMULATION_CONFIG["min_pressure"]
        max_pressure = SIMULATION_CONFIG["max_pressure"]

        return min_pressure <= pressure <= max_pressure