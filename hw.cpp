#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // 랜덤 시드 설정
    int target = std::rand() % 100 + 1; // 1부터 100까지의 랜덤 숫자 생성
    int guess;
    int attempts = 7;

    std::cout << "🎉 1부터 100까지의 숫자를 맞춰보세요! 🎉\n";

    while (attempts > 0) {
        std::cout << "남은 기회: " << attempts << "번\n";
        std::cout << "숫자를 입력하세요: ";
        std::cin >> guess;

        // 입력값 검증
        if (std::cin.fail() || guess < 1 || guess > 100) {
            std::cin.clear(); // 입력 스트림 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 잘못된 입력 무시
            std::cout << "⚠️ 1부터 100까지의 유효한 숫자를 입력하세요! ⚠️\n";
            continue;
        }

        if (guess == target) {
            std::cout << "🎉 정답입니다! 🎉\n";
            break;
        } else if (guess < target) {
            std::cout << "📉 더 큰 숫자를 입력하세요.\n";
        } else {
            std::cout << "📈 더 작은 숫자를 입력하세요.\n";
        }

        attempts--;

        if (attempts == 0) {
            std::cout << "😢 기회를 모두 소진했습니다. 정답은 " << target << "였습니다.\n";
        }
    }

    return 0;
}