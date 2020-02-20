import java.util.*;

public class BOJ1991{

    // public static class TreeNode{
    //     public char NodeValue;
    //     public TreeNode left;
    //     public TreeNode right;

    //     public TreeNode(char NodeValue){
    //         this.NodeValue = NodeValue;
    //         this.left = null;
    //         this.right = null;
    //     }

    //     public void setLeft(TreeNode left){
    //         this.left = left;
    //     }

    //     public void setRight(TreeNode right){
    //         this.right = right;
    //     }

    //     public TreeNode getLeft(){
    //         return left;
    //     }

    //     public TreeNode getRight(){
    //         return right;
    //     }

    // }

    // A[i][0] = A[i]의 left child, A[i][1] = A[i] 의 right child

    public static String A[][] = new String[26][2];

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        while(n-- != 0){
            String root = sc.next();
            String left = sc.next();
            String right = sc.next();

            A[root.charAt(0) - 'A'][0] = left;
            A[root.charAt(0) - 'A'][1] = right;
        }

        Preorder(0);
        System.out.println();
        Inorder(0);
        System.out.println();
        PostOrder(0);
        System.out.println();


    }

    public static void Preorder(int root){

        System.out.print((char)(root + 'A'));
        if(!A[root][0].equals(".")){
            Preorder(A[root][0].charAt(0) - 'A');
        }
        if(!A[root][1].equals(".")){
            Preorder(A[root][1].charAt(0) - 'A');
        }

    }

    public static void Inorder(int root){


        if(!A[root][0].equals(".")){
            Inorder(A[root][0].charAt(0) - 'A');
        }
        System.out.print((char)(root + 'A'));
        if(!A[root][1].equals(".")){
            Inorder(A[root][1].charAt(0) - 'A');
        }




    }

    public static void PostOrder(int root){

        
        if(!A[root][0].equals(".")){
            PostOrder(A[root][0].charAt(0) - 'A');
        }
        
        if(!A[root][1].equals(".")){
            PostOrder(A[root][1].charAt(0) - 'A');
        }

        System.out.print((char)(root + 'A'));


    }



}