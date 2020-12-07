package orderSystem;

import java.util.Scanner;

public class main {
	
	public static void main(String[] args) {
		
		OrderHelper orderhelper = new OrderHelper();
		Scanner scanner = new Scanner(System.in);
		int choice = 0;
		
		while(true) {
				orderhelper.printChoices();
			try {
				choice = Integer.parseInt(scanner.nextLine());
				if(choice < 1 || choice > 4) {
					throw new NumberFormatException();
				}
				else {
					orderhelper.choiceOrder(choice);
					orderhelper.printOrders();
				}
			} catch (NumberFormatException e) {
				System.out.println("Pleas chose a valid number");
			}
		}
		
	}

}
