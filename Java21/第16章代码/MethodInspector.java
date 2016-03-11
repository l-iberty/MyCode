import java.lang.reflect.*;

public class MethodInspector{
	public static void main(String[] arg){
		Class inspect;
		try{
			if(arg.length > 0)
				inspect = Class.forName(arg[0]);
			else
				inspect = Class.forName("MethodInspector");
			
			Method[] methods = inspect.getDeclaredMethods();
			
			for(int i = 0; i < methods.length; i++){
				Method methVal = methods[i];
				
				Class returnVal = methVal.getReturnType();
				int mod = methVal.getModifiers();
				String modVal = Modifier.toString(mod);
				Class[] paramVal = methVal.getParameterTypes();
				
				StringBuilder params = new StringBuilder();
				for(int j = 0; j < paramVal.length; j++){
					if(j > 0)
						params.append(",");
					params.append(paramVal[j].getName());
				}
				
				System.out.println("Method: " + methVal.getName() + "()");
				System.out.println("Returntype: " + returnVal.getName());
				System.out.println("Modifier: " + modVal);
				System.out.println("Parameters: " + params + "\n");
			}
		}catch(ClassNotFoundException e){
			System.out.println(e);
		}
	}
}