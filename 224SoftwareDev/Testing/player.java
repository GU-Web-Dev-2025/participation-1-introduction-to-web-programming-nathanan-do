public class player {
    
    public static void main(String args[]){

        int maxHealth = 100;
        int currentHealth = 1010;
        int level = 0;

        if(currentHealth>maxHealth){
            level++;
            System.out.print("Player leveled up! Level: ");
            System.out.print(level);
            currentHealth = 0;
        }
        else if(currentHealth == maxHealth){
            System.out.println("Uma uma, sayonara");
        }
    }
    
    //public static void main(String args[]){

   

}

class attributes{
    int playerhealth = 1000;
}
