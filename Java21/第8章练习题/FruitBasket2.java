import java.util.*;

// 散列映射

public class FruitBasket2{
	public static void main(String[] arg){
		HashMap<Integer, Fruit> hash = new HashMap<>();
		
		Fruit[] fruit = new Fruit[3];
		
		fruit[0] = new Fruit("Apple", 12, 5.67F);
	    hash.put(0, fruit[0]);
	
	    fruit[1] = new Fruit("Grape", 34, 8.90F);
	    hash.put(1, fruit[1]);
	
	    fruit[2] = new Fruit("Strawberry", 50, 15.45F);
	    hash.put(2, fruit[2]);
		
		for(int i = 0; i < fruit.length; i++){
			System.out.println("Name : " + hash.get(i).name);
		    System.out.println("Number : " + hash.get(i).number);
		    System.out.println("Price : $" + hash.get(i).price);
			System.out.println("\n");
		}
	}
}

/*
class Fruit{
	String name;
	int number;
	float price;
	
	Fruit(String inName, int inNumber, float inPrice){
		this.name = inName;
		this.number = inNumber;
		this.price = inPrice;
	}
} */