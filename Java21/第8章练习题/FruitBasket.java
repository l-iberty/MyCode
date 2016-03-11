import java.util.*;

// Á´±í·½Ê½

public class FruitBasket{
	public static void main(String[] arg){
		ArrayList<Fruit> list = new ArrayList<Fruit>();
	
	    Fruit[] fruit = new Fruit[3];
	
	    fruit[0] = new Fruit("Apple", 12, 5.67F);
	    list.add(0, fruit[0]);
	
	    fruit[1] = new Fruit("Grape", 34, 8.90F);
	    list.add(1, fruit[1]);
	
	    fruit[2] = new Fruit("Strawberry", 50, 15.45F);
	    list.add(2, fruit[2]);
		
		for(int i = 0; i < fruit.length; i++){
		    System.out.println("Name : " + list.get(i).name);
		    System.out.println("Number : " + list.get(i).number);
		    System.out.println("Price : $" + list.get(i).price);
			System.out.println("\n");
	    }
	}
}

class Fruit{
	String name;
	int number;
	float price;
	
	Fruit(String inName, int inNumber, float inPrice){
		this.name = inName;
		this.number = inNumber;
		this.price = inPrice;
	}
}