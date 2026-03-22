#include "employee.hpp"
#include "full_time_employee.hpp"
#include "part_time_employee.hpp"
#include "freelancer.hpp"
#include "bonus_eligible.hpp"
#include "pay_sys.hpp"

int main () {
    PayrollSystem sys;
    Employee* fullt {new FullTimeEmployee};
    Employee* partt {new PartTimeEmployee};
    Employee* freet {new Freelancer};

    sys.addEmployee(fullt);
    sys.addEmployee(partt);
    sys.addEmployee(freet);

    sys.displayEmployees();

    sys.calculateAllSalaries();

    sys.findEmployee(2);

    return 0;
}
