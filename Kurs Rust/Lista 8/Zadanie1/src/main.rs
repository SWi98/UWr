fn dna_strand(dna: &str) -> String {
    dna.chars().map(|x|{
        match x{
            'A' => 'T',
            'T' => 'A',
            'G' => 'C',
            'C' => 'G',
            _ => '_'
        }
    }).collect()
}

fn main() {
    println!("Hello, world!");
}

#[test]
fn test1() {
    assert_eq!(dna_strand("AAAA"),"TTTT");
}

#[test]
fn test2(){
    assert_eq!(dna_strand("ATTGC"),"TAACG");
}

#[test]
fn test3(){
    assert_eq!(dna_strand("GTAT"),"CATA");
}