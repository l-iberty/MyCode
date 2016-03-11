import java.lang.reflect.*;

public class MainChecker{
	public static void main(String[] arg){
		Class check;
		try{
			if(arg.length < 1)
			    check = Class.forName("MainChecker");
			else
				check = Class.forName(arg[0]);
			
			Method[] methods = check.getDeclaredMethods();
            
			for(int i = 0; i < methods.length; i++){
				String methodName = methods[i].getName();
				
				int mod = methods[i].getModifiers();
				String modType = Modifier.toString(mod);
				
				Class returnVal = methods[i].getReturnType();
				String returnType = returnVal.getName();
				
				Class[] paraVal = methods[i].getParameterTypes();
				String paraName;
				if(paraVal.length != 1){
					System.out.println("Not an application program.Bad parameter.");
					break;
				}
				else
					paraName = paraVal[0].getName();
				
				if( methodName.equals("main") & returnType.equals("void") & modType.equals("public static") & paraName.equals("[Ljava.lang.String;") ){
					System.out.println(check.getName() + " is an application program");
					break;
				}
				else{
					System.out.println("Not an application program.");
					break;
				}
			}
				
		}catch(ClassNotFoundException e){
			System.out.println(e);
		}
	}
}