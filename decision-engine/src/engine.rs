use crate::alert::Alert;
use crate::decision::Decision;

pub struct DecisionEngine {
    alerts: Vec<Alert>,
}

impl DecisionEngine {
    pub fn new() -> Self {
        Self {
            alerts: Vec::new(),
        }
    }

    pub fn add_alert(&mut self, alert: Alert) {
        self.alerts.push(alert);
    }

    pub fn alert_count(&self) -> usize {
        self.alerts.len()
    }

    pub fn evaluate(&self, alert: &Alert) -> Decision {
        if alert.severity >= 5 {
            Decision::Block
        } else if alert.severity >= 3 {
            Decision::Warn
        } else {
            Decision::Allow
        }
    }

    pub fn highest_severity(&self) -> u8 {
        let mut max = 0;

        for alert in &self.alerts {
            if alert.severity > max {
                max = alert.severity;
            }
        }

        max
    }
}