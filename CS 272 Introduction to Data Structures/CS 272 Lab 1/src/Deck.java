
public class Deck {
	
	int CardDeckNum[] = new int[60];
	boolean isEmpty;
	String outputMessage;
	int amountInDeck;
	
	public Deck() {
		amountInDeck = 59;
		isEmpty = false;
		for (int i = 0; i <= 59; i++) {
			CardDeckNum[i] = i;
		}
		
		
	}
	
	public String toString() {
		// Use the nameOfCard to figure out the number with name 
		// then add it to a string that will be returned
		
		return outputMessage;
	}
	
	public void shuffleDeck() {
		int holder, numA, numB;
		
		amountInDeck = 60;
		
		for (int i = 0; i <= 50; i++) {
			numA = (int)(Math.random() * 60 ) + 0;
			numB = (int)(Math.random() * 60 ) + 0;
			
			if (numA == numB) {
				// Will do nothing because is the same 
			} else {
				holder = CardDeckNum[numA];
				CardDeckNum[numA] = CardDeckNum[numB];
				CardDeckNum[numB] = holder;
			}
			
		}
		
	}
	
	public void printDeck() {
		int count = 0;
		for (int x = 0; x <= 59; x++) {
			System.out.printf("%5d", CardDeckNum[x]);
			count ++;
			if (count == 10) {
				System.out.println("");
				count = 0;
			}
		}
		System.out.println("");
	}
	
	public String dealACard() {
		String card = toString();
		amountInDeck--;
		return card;
	}
	
	public boolean emptyDeck() {
		if (amountInDeck == 0) {
			isEmpty = true;
		} else {
			isEmpty = false;
		}
		
		return isEmpty;
	}
	
	public String nameOfCard() {
		// Use this to create figure out the card and report back to the toString
	}

}
