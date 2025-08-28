
public class Employee {
    
    int basesalary;
    int extrahours;
    int hourlyWage;
    
    public int calculateWage(int basesalary, int hourlyWage, int extrahours){
        return basesalary + (hourlyWage*extrahours);
    }

/*    public int getbasesalary(){
        return basesalary;
    }
    public int getextrahours(){
        return extrahours;
    }
    public int gethourlywage(){
        return hourlyWage;
    }
*/
    public int getBasesalary() {
        return basesalary;
    }

    public void setBasesalary(int basesalary) {
        this.basesalary = basesalary;
    }

    public int getExtrahours() {
        return extrahours;
    }

    public void setExtrahours(int extrahours) {
        this.extrahours = extrahours;
    }

    public int getHourlyWage() {
        return hourlyWage;
    }

    public void setHourlyWage(int hourlyWage) {
        this.hourlyWage = hourlyWage;
    }




}

