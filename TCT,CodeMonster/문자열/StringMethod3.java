
public class StringMethod3{
    public static void main(String[] args){
        // 아래 String 에서 .mp3파일만을 골라내기
        String str = "song.mp3, song.txt, song.html, song2.mp3, song.wmv, hi.mp3, hi.txt";

        //System.out.println(str.indexOf("zdd"));

        str = str.replaceAll(",", ""); // "," 없애기
        
        String convertedStr[] = str.split(" "); // " " 기준으로 String 분리해서 배열 형태로 저장

        for(int i=0; i<convertedStr.length; i++){
            if(convertedStr[i].indexOf(".mp3", convertedStr[i].length() - 5) != -1 ){
                System.out.println(convertedStr[i]);
            }
        }

    }
}