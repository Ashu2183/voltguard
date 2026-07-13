mod alert;
mod decision;
mod engine;
use alert::Alert;
use engine::DecisionEngine;
fn main() {
    println!("VoltGuard Decision Engine Started");
    let mut engine = DecisionEngine::new();
    let alert = Alert {
        source: String::from("Physics Engine"),
        severity: 3,
        message: String::from("Pump RPM exceeds safe threshold"),
    };
    engine.add_alert(alert);
    println!("Stored alerts: {}", engine.alert_count());
}