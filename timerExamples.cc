#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>

int main () {
    std::cout << "*** UTC CLOCK ***" << std::endl;
    std::chrono::utc_clock::time_point t1 = std::chrono::utc_clock::now();
    std::cout << "UTC time point             : " << t1 << std::endl;


    std::cout << std::endl << "*** SYSTEM CLOCK ***" << std::endl;
    std::chrono::system_clock::time_point t_sc = std::chrono::system_clock::now();
    std::cout << "System clock time point    : " << t_sc << std::endl;
    
    const std::time_t t_sc_t = std::chrono::system_clock::to_time_t(t_sc);
    std::cout << "Converted to time_t        : " << std::put_time(std::localtime(&t_sc_t), "%F %T") << std::endl;
    
    const std::chrono::system_clock::time_point recovered_t_sc  = std::chrono::system_clock::from_time_t(t_sc_t);
    std::cout << "Converted back to timepoint: " << recovered_t_sc << std::endl;


    std::cout << std::endl << "*** HIGH RESOLUTION CLOCK ***\nIt is one of either steady_clock or system_clock" << std::endl;
    std::chrono::high_resolution_clock::time_point t_hrc = std::chrono::high_resolution_clock::now();
    std::cout << "High res clock time point  : " << t_hrc << std::endl;


    std::cout << std::endl << "*** TAI CLOCK ***" << std::endl;
    std::chrono::high_resolution_clock::time_point t_tai = std::chrono::high_resolution_clock::now();
    std::cout << "Tai clock time point       : " << t_tai << std::endl;


    std::cout << std::endl << "*** STEADY CLOCK ***" << std::endl;
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::chrono::steady_clock::time_point t3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span_s = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);
    std::cout << "Steady clock is used for durations: " << time_span_s << " seconds" << std::endl;

    return 0;
}