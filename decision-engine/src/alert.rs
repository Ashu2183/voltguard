#[derive(Debug)]
pub struct Alert {
    pub source: String,
    pub severity: u8,
    pub message: String,
}