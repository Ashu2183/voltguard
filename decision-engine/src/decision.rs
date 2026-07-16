pub enum Decision {
    Allow,
    Warn,
    Block,
}

pub fn decision_reason(decision: &Decision) -> &'static str {
    match decision {
        Decision::Allow => "System operating normally",
        Decision::Warn => "Potential unsafe condition detected",
        Decision::Block => "Unsafe physical state detected",
    }
}