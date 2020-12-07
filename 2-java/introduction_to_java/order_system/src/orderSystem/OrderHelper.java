package orderSystem;

import java.util.ArrayList;

public class OrderHelper {

	private ArrayList<Food> orders;

	OrderHelper(){
		orders = new ArrayList<Food>();
	}


	public void printOrders() {
		if(orders.size() == 0) {
			System.out.println("\nThere are no orders");
		}
		else {
			System.out.println("\nCurrent orders are");
			for (int i = 0; i < orders.size(); i++) {
				System.out.println(i + "- " + orders.get(i));
			}
		}
	}

	public void printChoices() {
		System.out.print("\n"
				+ "Chose your order\n"
				+ "1 Beef\n"
				+ "2 Chicken\n"
				+ "3 Bean\n"
				+ "4 Pea\n"
				+ ":"
				);
	}

	private void addOrder(Food order) {
		orders.add(order);
	}

	public void choiceOrder(int choice) {

		if(choice == 1) {
			addOrder(new Beef());
		}
		else if(choice == 2) {
			addOrder(new Chicken());
		}
		else if(choice == 3) {
			addOrder(new Bean());
		}
		else if(choice == 4) {
			addOrder(new Pea());
		}
		else {
			System.out.println("Wrong selection");
			return;
		}

		System.out.println("Your order added");

	}


}
