#![no_std]
#![no_main]
#![feature(custom_test_frameworks)]
#![test_runner(crate::test_runner)]
#![reexport_test_harness_main="test_main"]
use core::panic::PanicInfo;

mod vga_buffer;

//Tests
#[cfg(test)]
fn test_runner(tests: &[&dyn Fn()]){
    //Runs all the tests which are headed by #[test_case]
    println!("Running {} tests",tests.len());
    for test in tests{
        test();
    }

}

#[test_case]
fn trivial_assertion(){
    print!("Trivial assertion... ");
    assert_eq!(1,1);
    println!("[ok]");
}

#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    println!("{}", info);
    loop {}
}

#[no_mangle]
pub extern "C" fn _start() -> ! {
    println!("Hellow UwU world ");
    
    #[cfg(test)]//only runs if `cargo test` command is used
    test_main(); 
    loop {}
}
