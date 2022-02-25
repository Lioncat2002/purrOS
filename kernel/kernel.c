void dummy_test_entrypoint(){
//to create a kernel entry point
}
void main(){
    char* video_memory=(char*)0xb8000;
    *video_memory='X';
}