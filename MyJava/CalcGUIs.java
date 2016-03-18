import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.Math;
import java.io.*;
import java.util.regex.*;
import java.util.*;

public class CalcGUIs extends JFrame implements ActionListener{
	JTextArea output;
	JButton mod,
	        sin, cos, tan, asin, acos, atan,
			exp, ln, lg,
			square, cube, sqrt, factorial, pow;
	JButton equal, plus, minus, multiply, divite, 
			clear, sign, Lbracket, Rbracket;
	JButton[] num = new JButton[14]; 
	
	GridBagLayout gridbag = new GridBagLayout();
	JPanel number = new JPanel();
	JPanel symbol = new JPanel();
	JPanel symbol2 = new JPanel();
	        
	public CalcGUIs(){
		super("Calculator");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLookAndFeel();
		setSize(420,270);
		setLayout(new BorderLayout());
		
		// 添加文本区域
		output = new JTextArea(3,10);
		output.setEditable(false);
		
		// 添加高级运算符
		mod = new JButton("Mod");
		sin = new JButton("sin");
		cos = new JButton("cos");
		tan = new JButton("tan");
		asin = new JButton("asin");
		acos = new JButton("acos");
		atan = new JButton("atan");
		exp = new JButton("e^x");
		ln = new JButton("ln");
		lg = new JButton("lg");
		square = new JButton("x^2");
		cube = new JButton("x^3");
		sqrt = new JButton("√");
		factorial = new JButton("n!");
		pow = new JButton("x^y");
		
		mod.addActionListener(this);
		sin.addActionListener(this);
		cos.addActionListener(this);
		tan.addActionListener(this);
		asin.addActionListener(this);
		acos.addActionListener(this);
		atan.addActionListener(this);
		exp.addActionListener(this);
		ln.addActionListener(this);
		lg.addActionListener(this);
		square.addActionListener(this);
		cube.addActionListener(this);
		sqrt.addActionListener(this);
		factorial.addActionListener(this);
		pow.addActionListener(this);
		
		GridLayout gr1 = new GridLayout(5,3);
		symbol.setLayout(gr1);
		symbol.add(mod);
		symbol.add(sin);
		symbol.add(cos);
		symbol.add(tan);
		symbol.add(asin);
		symbol.add(acos);
		symbol.add(atan);
		symbol.add(exp);
	    symbol.add(ln);
		symbol.add(lg);
		symbol.add(square);
		symbol.add(cube);
		symbol.add(sqrt);
		symbol.add(factorial);
		symbol.add(pow);
		
		
		// 添加数字及小数点
		number.setLayout(gridbag);
		for(int i = 0; i < num.length; i++){
			switch(i){
				case 10:
				    num[i] = new JButton(".");
					break;
				case 11:
				    num[i] = new JButton();
					break;
				case 12:
				    num[i] = new JButton("e");
					break;
				case 13:
				    num[i] = new JButton("π");
					break;
				default:
				    num[i] = new JButton("" + i);
			}	
		}
		addComponent(number, num[1], 0, 1, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[2], 1, 1, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[3], 2, 1, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[4], 0, 2, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[5], 1, 2, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[6], 2, 2, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[7], 0, 3, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[8], 1, 3, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[9], 2, 3, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[0], 0, 4, 2, 1, 20, 10, GridBagConstraints.BOTH);
		addComponent(number, num[10], 2, 4, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[11], 0, 0, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[12], 1, 0, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(number, num[13], 2, 0, 1, 1, 10, 10, GridBagConstraints.BOTH);
		
		// 添加基本符号
		symbol2.setLayout(gridbag);
		
		equal = new JButton("=");
		plus = new JButton("+");
		minus = new JButton("-");
		multiply = new JButton("*");
		divite = new JButton("/");
		clear = new JButton("C");
		sign = new JButton("±");
		Lbracket = new JButton("(");
		Rbracket = new JButton(")");
		
		addComponent(symbol2, Lbracket, 0, 0, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(symbol2, Rbracket, 1, 0, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(symbol2, multiply, 0, 1, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(symbol2, divite, 0, 2, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(symbol2, plus, 0, 3, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(symbol2, minus, 0, 4, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(symbol2, clear, 1, 1, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(symbol2, sign, 1, 2, 1, 1, 10, 10, GridBagConstraints.BOTH);
		addComponent(symbol2, equal, 1, 3, 1, 2, 10, 20, GridBagConstraints.BOTH);
		
		add(output, BorderLayout.NORTH);
		add(symbol, BorderLayout.WEST);
		add(number, BorderLayout.CENTER);
		add(symbol2, BorderLayout.EAST);
		setVisible(true);
	}
	
	private void addComponent(JPanel pane, JButton component, int gridx, int gridy, int gridwidth, 
	                          int gridheight, int weightx, int weighty, int fill){
		GridBagConstraints constraint = new GridBagConstraints();
		constraint.gridx = gridx;
		constraint.gridy = gridy;
		constraint.gridwidth = gridwidth;
		constraint.gridheight = gridheight;
		constraint.weightx = weightx;
		constraint.weighty = weighty;
		constraint.fill = fill;
		gridbag.setConstraints(component, constraint);
		component.addActionListener(this);
		pane.add(component);
	}
	
	private void setLookAndFeel(){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
			SwingUtilities.updateComponentTreeUI(this);
		}catch(Exception e){
			// do nothing
		}
	}
	
	public void actionPerformed(ActionEvent evt){
		JButton source = (JButton)evt.getSource();
		String button = source.getText();
		String outputStr = null;
		double Valoutput = 0F;
		double result = 0F;
		
		// 显示输入
		switch (button){
			case "0":
			    output.append("0");
				break;
			case "1":
			    output.append("1");
				break;
			case "2":
			    output.append("2");
				break;
			case "3":
			    output.append("3");
				break;
			case "4":
			    output.append("4");
				break;
			case "5":
			    output.append("5");
				break;
			case "6":
			    output.append("6");
				break;
			case "7":
			    output.append("7");
				break;
			case "8":
			    output.append("8");
				break;
			case "9":
			    output.append("9");
				break;
			case "e":
			    output.append("e");
				break;
			case "π":
			    output.append("π");
				break;
			case ".":
			    output.append(".");
				break;
			case "±":
			    output.append("-");
				break;
			case "+":
			    output.append("+");
				break;
			case "-":
			    output.append("-");
				break;
			case "*":
			    output.append("*");
				break;
			case "/":
			    output.append("/");
				break;
			case "(":
			    output.append("(");
				break;
			case ")":
			    output.append(")");
				break;
			case "Mod":
			    output.append("%");
				break;
			case "x^y":
			    output.append("^");
				break;
				
		    // 清屏
			case "C":
				output.setText("");
				break;
		}
		

		    
		// 一元运算符
		switch (button){
			case "sin":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Math.sin(Valoutput);
				output.append("\n" + result);
				break;
			case "cos":
			    outputStr = output.getText();
			    Valoutput = Double.parseDouble(outputStr);
				result = Math.cos(Valoutput);
				output.append("\n" + result);
				break;
			case "tan":
			    outputStr = output.getText();
			    Valoutput = Double.parseDouble(outputStr);
				result = Math.tan(Valoutput);
				output.append("\n" + result);
				break;
			case "asin":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Math.asin(Valoutput);
				output.append("\n" + result);
				break;
			case "acos":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Math.acos(Valoutput);
				output.append("\n" + result);
				break;
			case "atan":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Math.atan(Valoutput);
				output.append("\n" + result);
				break;
			case "e^x":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Math.exp(Valoutput);
				output.append("\n" + result);
				break;
			case "ln":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Math.log(Valoutput);
				output.append("\n" + result);
				break;
			case "lg":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Math.log10(Valoutput);
				output.append("\n" + result);
				break;
			case "x^2":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Valoutput*Valoutput;
				output.append("\n" + result);
				break;
			case "x^3":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Valoutput*Valoutput*Valoutput;
				output.append("\n" + result);
				break;
			case "√":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Math.sqrt(Valoutput);
				output.append("\n" + result);
				break;
			case "n!":
			    outputStr = output.getText();
				Valoutput = Double.parseDouble(outputStr);
				result = Factorial(Valoutput);
				output.append("\n" + result);
				break;
		}
		
		if(source == equal){
			String[] s1 = decompose(output.getText());
			String s2 = combine(s1);
			result = subCalculate(s2);
			output.append("\n" + result);
		}
	}
	
	// 分解括号
	private String[] decompose(String input){
		ArrayList<String> tmpInput = new ArrayList<>();
		String[] arrayInput;
		char ch, tmpCh1, tmpCh2;
		String trans;
		StringBuffer buff = new StringBuffer();
		
		for(int index = 0; index < input.length(); index++){
			ch = input.charAt(index);
			/** 如果括号是首字符要特殊处理:跳过,进入下一轮迭代即可 **/
			if(index == 0 && ch == '(')
				continue;

			if( ch != '(' && ch != ')'){
				buff.append( String.valueOf(ch) );
					
				if(index == input.length()-1)
					tmpInput.add(buff.toString());
				else
					continue;
			}else{
				trans = buff.toString();
				tmpCh1 = trans.charAt(0);
				tmpCh2 = trans.charAt(trans.length()-1);
				/**
				 * 从括号内截取的字符串有这样的特点:
				 * 首字符和末尾字符都不是运算符
				 **/
				if( (tmpCh1 != '+' && tmpCh1 != '-' && tmpCh1 != '/' && tmpCh1 != '*' && tmpCh1 != '%') &&
					(tmpCh2 != '+' && tmpCh2 != '-' && tmpCh2 != '/' && tmpCh2 != '*' && tmpCh2 != '%') ){
					
					double transVal = calculate(trans);
					tmpInput.add(String.valueOf(transVal));
				}
				else
					tmpInput.add(buff.toString());
				
				buff = new StringBuffer();
			}
		}
		arrayInput = new String[tmpInput.size()];
		for(int n = 0; n < tmpInput.size(); n++){
			arrayInput[n] = tmpInput.get(n);
		}
		System.out.println("decompose(): " + Arrays.toString(arrayInput));
		return arrayInput;
	}
	
	// 括号处理完后重新组装为String
	private String combine(String[] field){
		StringBuilder build = new StringBuilder();
		for(int a = 0; a < field.length; a++)
			build.append(field[a]);
		
		System.out.println("combine(): " + build.toString());
		return build.toString();
	}
	
	// 对combine()返回的String调用calculate()
	private double subCalculate(String input){
		return calculate(input);
	}
	
	/** 核心计算方法calculate() **/
	private double calculate(String input){
		// 二元运算符
		ArrayList<String> numStr = new ArrayList<>();
		ArrayList<Character> symCh = new ArrayList<>();
		double[] val;
		char[] sym;
		StringBuffer buff = new StringBuffer();
		int c;
		char ch;
		int i, countNum = 0, countSym = 0;
		double result = 0F;
		
		/** 有时会碰到只输入一个数字就按等号的情况 **/
		int p = 0;
		char r;
		for(i = 0; i < input.length(); i++){
			r = input.charAt(i);
			if(r == '+' || r == '-' || r == '*' || r == '/' || r == '%')
				p++;
		}
		if(p == 0)
			return Double.parseDouble(input);
		
			// 解析
			String tmpStr = input;
			for(i = 0; i < tmpStr.length(); i++){
				ch = tmpStr.charAt(i);
				c = (int)ch;
				
				if((c > 47 && c < 58) || ch == '.'){
					buff.append( String.valueOf(ch) );
					continue;
				}
				numStr.add(buff.toString());
				buff = new StringBuffer();
				
				if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
					symCh.add(ch);	
			}
			numStr.add(buff.toString()); // 最后输入的数字在循环结束后还在buff里,需将其加入链表.
			
			// 存储
			val = new double[numStr.size()];
			sym = new char[symCh.size()];
			for(i = 0; i < numStr.size(); i++)
				val[i] = Double.parseDouble(numStr.get(i));
		
			for(i = 0; i < symCh.size(); i++)
				sym[i] = symCh.get(i);
			

			/**
			 * 运算过程分两类:
			 * 1.乘除,取模;
			 * 2.加减;
			 * 3.混合运算.
			 **/
			 
			int count1 = 0, 
				count2 = 0; // count1统计+,-;count2统计*,/
			for(i = 0; i < sym.length; i++){
				if(sym[i] == '*' || sym[i] == '/' || sym[i] == '%')
					count2++;
				if(sym[i] == '+' || sym[i] == '-')
					count1++;
			}
			
			/** 乘除,取模 **/
			if(count2 > 0 && count1 == 0){
				if (sym[0] == '*')
					result = val[0] * val[1];
				else if	(sym[0] == '/')
					result = val[0] / val[1];
				else if	(sym[0] == '%')
					result = val[0] % val[1];
				
				for(i = 1; i < sym.length; i++){
					if(sym[i] == '*')
						result *= val[i+1];
					else if(sym[i] == '/')
						result /= val[i+1];
					else if(sym[i] == '%')
						result %= val[i+1];
				}
			}
			/** 加减 **/
			else if(count1 > 0 && count2 == 0){
				if (sym[0] == '+')
					result = val[0] + val[1];
				else if	(sym[0] == '-')
					result = val[0] - val[1];
				
				for(i = 1; i < sym.length; i++){
					if(sym[i] == '+')
						result += val[i+1];
					else if(sym[i] == '-')
						result -= val[i+1];
				}
			}
			/** 混合运算 **/
			else if(count1 > 0 && count2 > 0){
				// 遍历sym[],将+,-号加入tmpSymList
				ArrayList<Character> tmpSymList = new ArrayList<>();
				int count = 0;
				for(i = 0; i < sym.length; i++){
					if(sym[i] == '+' || sym[i] == '-'){
						tmpSymList.add(sym[i]);
						count++;
					}
				}
				char[] tmpSym = new char[count];
				for(i = 0; i < tmpSym.length; i++)
					tmpSym[i] = tmpSymList.get(i);
			
				System.out.println("tmpSym[]: " + Arrays.toString(tmpSym));
			
				// 遍历val[],处理运算符优先级
				count = 0;
				ArrayList<Double> tmpValList = new ArrayList<>();
				for(i = 0; i < sym.length; i++){
					if(sym[i] == '+' || sym[i] == '-'){
						if(( i > 0 && i != sym.length-1 ) && (sym[i-1] != '*' && sym[i-1] != '/')){
							tmpValList.add(val[i]);
							count++;
						}else if(i == 0){
							tmpValList.add(val[i]);
							count++;
						}
					}
					else if(sym[i] == '*' || sym[i] == '/' || sym[i] == '%'){
						tmpValList.add( subCalc(sym, val, i) );
						count++;
						while( i+1 < sym.length && (sym[i+1] == '*' || sym[i+1] == '/' || sym[i+1] == '%') )
							i++;
					}
					
					if(i == sym.length-1 && (sym[i] == '+' || sym[i] == '-')){
						if(sym[i-1] == '+' || sym[i-1] == '-'){
							tmpValList.add(val[i]);
							count++;
							tmpValList.add(val[i+1]);
							count++;
						}else{
							tmpValList.add(val[i+1]);
							count++;				
						}
					}
				}
				double[] tmpVal = new double[count];
				for(i = 0; i < tmpVal.length; i++)
					tmpVal[i] = tmpValList.get(i);
			
				System.out.println("tmpVal[]: " + Arrays.toString(tmpVal));
			
				//  用新的数组完成运算
				if (tmpSym[0] == '+')
					result = tmpVal[0] + tmpVal[1];
				else if	(tmpSym[0] == '-')
					result = tmpVal[0] - tmpVal[1];
				
				for(i = 1; i < tmpSym.length; i++){
					if(tmpSym[i] == '+')
						result += tmpVal[i+1];
					else if(tmpSym[i] == '-')
						result -= tmpVal[i+1];
				}
			}
			
			return result;
		
	} /** method calculata() ends here. **/
	
	// 此方法处理乘除法和取模子运算式
	private double subCalc(char[] sym, double[] val, int index){
		double subResult = 0F;
		
		if(sym[index] == '*')
			subResult = val[index] * val[index+1];
		else if(sym[index] == '/')
			subResult = val[index] / val[index+1];
		else if(sym[index] == '%')
			subResult = val[index] % val[index+1];
		
		for(int n = index+1; n < sym.length && (sym[n] == '*' || sym[n] == '/'); n++){
			if(sym[n] == '*')
				subResult *= val[n+1];
			else if(sym[n] == '/')
				subResult /= val[n+1];
			else if(sym[n] == '%')
				subResult %= val[n+1];
		}
		
		return subResult;
	}
	
	private double Factorial(double n){
		if(n - Math.round(n) != 0)
			return Double.NaN;
		
		if(n == 0)
			return 1;
		else
			return n * Factorial(n-1);
	}
	
	public static void main(String[] arg){
		new CalcGUIs();
	}
}