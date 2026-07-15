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

    let decision = engine.evaluate(&alert);

    match decision {
        decision::Decision::Allow => println!("Decision: ALLOW"),
        decision::Decision::Warn => println!("Decision: WARN"),
        decision::Decision::Block => println!("Decision: BLOCK"),
    }

    println!("Reason: Severity checked successfully");

    engine.add_alert(alert);

    println!("Highest severity: {}", engine.highest_severity());
    println!("Stored alerts: {}", engine.alert_count());
    }