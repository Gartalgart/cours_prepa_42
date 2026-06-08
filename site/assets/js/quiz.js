document.addEventListener('DOMContentLoaded', function () {
  var total = 0;
  var correct = 0;

  document.querySelectorAll('.quiz-question').forEach(function (question) {
    var correctIndex = parseInt(question.dataset.correct, 10);
    var options = question.querySelectorAll('.quiz-option');
    var checkBtn = question.querySelector('.quiz-check');
    var feedbackOk = question.querySelector('.quiz-feedback-correct');
    var feedbackKo = question.querySelector('.quiz-feedback-incorrect');
    var selected = null;
    var answered = false;

    total++;

    options.forEach(function (option, index) {
      option.addEventListener('click', function () {
        if (answered) return;
        options.forEach(function (o) { o.classList.remove('selected'); });
        option.classList.add('selected');
        selected = index;
        checkBtn.disabled = false;
      });
    });

    checkBtn.addEventListener('click', function () {
      if (selected === null || answered) return;
      answered = true;
      checkBtn.disabled = true;
      options.forEach(function (o) { o.style.pointerEvents = 'none'; });

      if (selected === correctIndex) {
        options[selected].classList.add('correct');
        feedbackOk.hidden = false;
        correct++;
      } else {
        options[selected].classList.add('incorrect');
        options[correctIndex].classList.add('correct');
        feedbackKo.hidden = false;
      }
      updateScore();
    });
  });

  function updateScore() {
    var scoreEl = document.getElementById('quiz-score');
    if (!scoreEl) return;
    var answered = document.querySelectorAll('.quiz-question .quiz-check[disabled]').length;
    if (answered === 0) {
      scoreEl.textContent = '';
      return;
    }
    scoreEl.textContent = correct + ' / ' + answered + ' bonne' + (correct > 1 ? 's' : '') + ' réponse' + (correct > 1 ? 's' : '');
    scoreEl.className = 'quiz-score ' + (correct === answered ? 'quiz-score-perfect' : '');
  }
});
