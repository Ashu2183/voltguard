# flow.py

import math
from config import SIMULATION_CONFIG


class FlowCalculator:
    def __init__(self):
        self.pipe_diameter = SIMULATION_CONFIG["pipe_diameter"]

    def calculate_flow_rate(self, velocity):
        """
        Calculate flow rate (m³/s)

        Formula:
            Q = A × V
            A = π × (d²) / 4
        """

        area = math.pi * (self.pipe_diameter ** 2) / 4
        flow_rate = area * velocity

        return round(flow_rate, 4)

    def is_safe_flow(self, flow_rate):
        """
        Check whether flow rate is within safe limit.
        """

        return flow_rate <= SIMULATION_CONFIG["max_flow_rate"]