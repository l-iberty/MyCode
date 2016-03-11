import java.util.*;

public class Directory{
	static ArrayList<Person> personList = new ArrayList<>();
	
	public static void main(String[] arg){
		DirectoryManager dm = new DirectoryManager();
		DirectoryManager.showTips();
	}
}

class DirectoryManager{
	private int choice;
	private ManageChoice mce = new ManagerChoice();
	
	public void showTips(){
		System.out.println("-----------Directory Manager------------");
		System.out.println("<1> Add to Directory");
		System.out.println("<2> Delete Directory");
		System.out.println("<3> Search Directory");
		System.out.println("<4> Show Directory");
		System.out.println("<5> Back");
			
		while(true){
			System.out.println("------------------------------------------");
			System.out.println("\n>>> Please enter 0-5,others are invalid.>>>");
		
			try{
				Scanner getChoice = new Scanner(System.in);
				choice = getChoice.nextInt(); // get user's choice
			}catch(InputMismatchException e){
				System.out.println(">> Invalid Input!");
			}
			
			if(choice != 5){
				mce.manageChoice(choice);
				choice = -1; /** If I don't do this,there will be a singular BUG
								 when the user enters something unexpected. **/
			}
			else
				break;
		}
	}
	
	private class ManageChoice{
	
		public void manageChoice(int inChoice){
			switch(inChoice){
				case 1:
					addInformation();
					break;
		
				case 2:
					delInformation();
					break;
			
				case 3:
					searchInformation();
					break;
				
				case 4:
					if(Directorys.personList.size() == 0)
						System.out.println(">> No Record in the Directory");
					else
						showInformation();
				
					break;
			}
		}
		
		private void addInformation(){
			String inName;
			String inTelephone;
	
			System.out.print("\nPlease enter the name: ");
			Scanner getName = new Scanner(System.in);
			inName = getName.nextLine();
			
			System.out.print("Please enter the telephone number: ");
			Scanner getTel = new Scanner(System.in);
			inTelephone = getTel.nextLine();
				
			Person ref = new Person(inName, inTelephone);
			Directorys.personList.add(ref);
			
			if(Directorys.personList.size() > 0){
				System.out.println("------------------------------------------");
				System.out.println("Done Successfully!");
			}
			else{
				System.out.println("------------------------------------------");
				System.out.println("Fail to add information!");
			}
		}
		
		private void delInformation(){
			int tmpChoice = -1;
		
			if(Directorys.personList.size() == 0)
				System.out.println(">> No Record in the Directory");
			else{
				System.out.println("------------------------------------------");
				System.out.println("\nAll the person's information is as following,"+
						"you can enter the order number to delete the matching one."+
						"If you need to delete all the records,enter \"0\"."+
						"If you are meant to return,please enter any character other than the order number and \"0\".");
				System.out.println("------------------------------------------");
			
				showInformation();
				System.out.println("");
			
				try{
					Scanner getTmpChoice = new Scanner(System.in);
					tmpChoice = getTmpChoice.nextInt();
				}catch(InputMismatchException e){
					;
				}
				
				if(tmpChoice == 0){
					Directorys.personList.clear();
					System.out.println(">> Deleted! Enter \"4\" to check the result.");
				}
				else if(tmpChoice-1 < Directorys.personList.size() && tmpChoice-1 >= 0){
					Directorys.personList.remove(tmpChoice-1);
					System.out.println(">> Deleted! Enter \"4\" to check the result.");
				}
				else
					;
			}
		}
		
		private void searchInformation(){
			String tmpName;
			String tmpTel;
			String search;
			int j; // j means the index of the element
			int count; /** each time the program finds a matching element
						   the variable count will increase by 1. **/
						   
			if(Directorys.personList.size() == 0){
				System.out.println(">> No Record in the Directory");
			}else{
				System.out.println("------------------------------------------");
				System.out.println("<A> Enter \"A\" to search via name\n"+
								   "<B> Enter \"B\" to search via telephone number");
				search = new Scanner(System.in).nextLine();
							
				if(search.equals("a") || search.equals("A")){
					System.out.print("Please enter the name to search: ");
					tmpName = new Scanner(System.in).nextLine();
				
					for(j = 0, count = 0; j < Directorys.personList.size(); j++){
						Person tmp = Directorys.personList.get(j);
					
						if(tmp.name.equals(tmpName)){
							count++;
							System.out.println("------------------------------------------");
							System.out.println("\nSearching...");
							System.out.println("Name: " + tmp.name);
							System.out.println("Telephone Number: " + tmp.telephone);
						}
					}
					if(count == 0)
						System.out.println("Not Found!");
				}
				else if(search.equals("b") || search.equals("B")){
					System.out.print("Please enter the telephone number to search: ");
					tmpTel = new Scanner(System.in).nextLine();
				
					for(j = 0, count = 0; j < Directorys.personList.size(); j++){
						Person tmp = Directorys.personList.get(j);
					
						if(tmp.telephone.equals(tmpTel)){
							count++;
							System.out.println("------------------------------------------");
							System.out.println("\nSearching...");
							System.out.println("Name: " + tmp.name);
							System.out.println("Telephone Number: " + tmp.telephone);
						}
					}
					if(count == 0)
						System.out.println("Not Found!");
				}
				else
					System.out.println(">> Invalid Input!Unable to search!");
			}
		}
		
		private void showInformation(){
			System.out.print("\n------------------------------------------");
			for(int i = 0; i < Directorys.personList.size(); i++){
				Person tmp = Directorys.personList.get(i);
				System.out.println("\nPerson " + (i+1) + ":");
				System.out.println("Name: " + tmp.name);
				System.out.println("Telephone Number: " + tmp.telephone);
			}
		}
	}
}

class Person{
	String name;
	String telephone;
	
	public Person(String inName, String inTelephone){
		name = inName;
		telephone = inTelephone;
	}
}