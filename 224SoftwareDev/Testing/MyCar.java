public class MyCar{


    static void drive(int speed, String dest){
        System.out.println(speed);
    }
    
    static void drive(int speed, int dest){
        System.out.println(speed);
    }
    
    static void drive(String dest, int speed){
        System.out.println(speed);
    }

    public static void main(String args[]){

        var mycar = new MyCar();

        drive("sui", 77);
        
        mycar.drive("sui", 55);
        mycar.drive(34, 678);
        
    }    

}
