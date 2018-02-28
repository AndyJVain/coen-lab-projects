public class ImageMain {
	public static void main(String args[]) {
		String image1Name = new String("\\\\SAMBA1\\avainaus\\dcengr\\My Documents\\eclipse-workspace\\Lab 2\\img\\images\\pkmn.png");
		String image2Name = new String("\\\\SAMBA1\\avainaus\\dcengr\\My Documents\\eclipse-workspace\\Lab 2\\img\\images\\scene.png");
		
		ImageSimilarity image1 = new ImageSimilarity();
		ImageSimilarity image2 = new ImageSimilarity();
		
		image1.histogram(image1Name);
		image2.histogram(image2Name);
		
		double imageDifference = image1.euclideanDistance(image2);
		System.out.println(imageDifference);
	}
}
