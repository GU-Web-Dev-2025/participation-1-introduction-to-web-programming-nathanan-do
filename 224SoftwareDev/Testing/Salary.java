public class Salary{
       public static void main(String args[]){

        int basesalary = 50_000;
        int extrahours = 10;
        int hourlyWage = 20;

        var employee = new Employee();
        employee.basesalary = 50_000;
        employee.hourlyWage = 20;
        employee.extrahours = 10;

        if(employee.extrahours < 0){throw new IllegalArgumentException("BaseSalary cannot be negative");}

        int wage = employee.calculateWage(basesalary, hourlyWage, extrahours);
        //int wage = employee.calculateWage(10);

        System.out.println("Wage: " + " Base Salary: $" + basesalary + " + " + "Hourly Rate $" + hourlyWage + " x " + "Extra " + extrahours + " Hour = $" + wage);

    }

    

}

// Sublass is member

