struct tracer {
    tracer() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;   
    }
    
    tracer(tracer const&) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;   
    }
    
    tracer(tracer&&) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;   
    }
    
    ~tracer() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;   
    }
};

