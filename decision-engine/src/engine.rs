use crate::alert::Alert;

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
}