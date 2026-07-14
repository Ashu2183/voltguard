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
        match alert.severity {
            1 | 2 => Decision::Allow,
            3 => Decision::Warn,
            _ => Decision::Block,
        }
    }
}