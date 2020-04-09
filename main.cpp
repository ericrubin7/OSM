#include <iostream>
#include "osm.h"
using namespace std;

int main() {
    cout << "OSM OPERATION TIME: " <<osm_operation_time(10000) << " NANOSECS" << endl;
    cout << "OSM FUNCTION TIME: " << osm_function_time(10000)<< " NANOSECS" << endl;
    cout << "OSM TRAP:"  << osm_syscall_time(10000) << " NANOSECS" << endl;
    return 0;
}