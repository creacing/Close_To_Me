<template>
  <div
    id="search"
    :class="[showSearch ? 'show--search' : '']"
    v-show="showSearch"
    ref="searchDialog"
  >
    <div class="inner search-inner">
      <div class="header">
        <span class="icon">
          <i class="ic i-search"></i>
        </span>
        <div class="search-input-container">
          <div class="ais-SearchBox">
            <form action role="search" class="ais-SearchBox-form" novalidate>
              <input
                class="ais-SearchBox-input search-input"
                type="search"
                placeholder="文章搜索"
                autocomplete="off"
                autocorrect="off"
                autocapitalize="off"
                spellcheck="false"
                maxlength="512"
                @input="searchForArticles"
                v-model="inputVal"
              />
              <button
                class="ais-SearchBox-submit"
                type="submit"
                title="Submit the search query."
                hidden
              >
                <svg class="ais-SearchBox-submitIcon" width="10" height="10" viewBox="0 0 40 40">
                  <path
                    d="M26.804 29.01c-2.832 2.34-6.465 3.746-10.426 3.746C7.333 32.756 0 25.424 0 16.378 0 7.333 7.333 0 16.378 0c9.046 0 16.378 7.333 16.378 16.378 0 3.96-1.406 7.594-3.746 10.426l10.534 10.534c.607.607.61 1.59-.004 2.202-.61.61-1.597.61-2.202.004L26.804 29.01zm-10.426.627c7.323 0 13.26-5.936 13.26-13.26 0-7.32-5.937-13.257-13.26-13.257C9.056 3.12 3.12 9.056 3.12 16.378c0 7.323 5.936 13.26 13.258 13.26z"
                  />
                </svg>
              </button>
              <button
                class="ais-SearchBox-reset"
                type="reset"
                title="Clear the search query."
                hidden
              >
                <svg class="ais-SearchBox-resetIcon" viewBox="0 0 20 20" width="10" height="10">
                  <path
                    d="M8.114 10L.944 2.83 0 1.885 1.886 0l.943.943L10 8.113l7.17-7.17.944-.943L20 1.886l-.943.943-7.17 7.17 7.17 7.17.943.944L18.114 20l-.943-.943-7.17-7.17-7.17 7.17-.944.943L0 18.114l.943-.943L8.113 10z"
                  />
                </svg>
              </button>
            </form>
          </div>
        </div>
        <span class="close-btn" @click="closeSearchDialog">
          <i class="ic i-times-circle"></i>
        </span>
      </div>
      <div class="results">
        <div class="inner">
          <div id="search-stats">
            <div class="ais-Stats">
              <span class="ais-Stats-text">
                3 ms 内找到 94 条结果
                <span class="algolia-powered"></span>
                <hr />
              </span>
            </div>
          </div>
          <div id="search-hits">
            <div>
              <div class="ais-Hits">
                <ol class="ais-Hits-list">
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-510/week-12/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMD 510.
                        Object-Oriented App Develop
                      </span>Week 12.
                      <mark>J</mark>avaFx
                    </a>
                  </li>
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-510/week-11/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMD 510.
                        Object-Oriented App Develop
                      </span>Week 11.
                      <mark>J</mark>ava Database Connectivity
                    </a>
                  </li>
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-510/week-1/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMD 510.
                        Object-Oriented App Develop
                      </span>Week 1.
                      <mark>J</mark>ava Fundamental / Best programming
                      practices
                    </a>
                  </li>
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-565/lecture-9/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMM 565.
                        Rich Internet Applications
                      </span>Lecture 9.
                      <mark>J</mark>avaScript - ES6 Module
                    </a>
                  </li>
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-565/lecture-5/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMM 565.
                        Rich Internet Applications
                      </span>Lecture 5.
                      <mark>J</mark>avaScript -
                      <mark>J</mark>SON
                      &amp; AJAX
                    </a>
                  </li>
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-565/lecture-4/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMM 565.
                        Rich Internet Applications
                      </span>Lecture 4.
                      <mark>J</mark>avaScript – ES6+ (ES 2015+)
                    </a>
                  </li>
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-565/lecture-3/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMM 565.
                        Rich Internet Applications
                      </span>Lecture 3.
                      <mark>J</mark>avaScript – Namespace
                    </a>
                  </li>
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-565/lecture-2/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMM 565.
                        Rich Internet Applications
                      </span>Lecture 2.
                      <mark>J</mark>avaScript – DOM Introduction and
                      Selecting Elements
                    </a>
                  </li>
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-565/lecture-10/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMM 565.
                        Rich Internet Applications
                      </span>Lecture 10. ReactJS -
                      <mark>J</mark>avaScript library for
                      building user interfaces
                    </a>
                  </li>
                  <li class="ais-Hits-item item">
                    <a href="/computer-science/mse/itmd-565/lecture-1/" data-pjax-state>
                      <span>
                        计算机科学
                        <i class="ic i-angle-right"></i>Master of Software
                        Engineering
                        <i
                          class="ic i-angle-right"
                        ></i>ITMM 565.
                        Rich Internet Applications
                      </span>Lecture 1.
                      <mark>J</mark>avaScript – Language and Syntax
                    </a>
                  </li>
                </ol>
              </div>
            </div>
          </div>
          <div id="search-pagination">
            <div class="ais-Pagination pagination">
              <ul class="ais-Pagination-list">
                <li
                  class="ais-Pagination-item pagination-item ais-Pagination-item--previousPage ais-Pagination-item--disabled disabled-item"
                >
                  <span class="ais-Pagination-link page-number">
                    <i class="ic i-angle-left"></i>
                  </span>
                </li>
                <li
                  class="ais-Pagination-item pagination-item ais-Pagination-item--page ais-Pagination-item--selected current"
                >
                  <a class="ais-Pagination-link page-number" aria-label="1" href="#">1</a>
                </li>
                <li class="ais-Pagination-item pagination-item ais-Pagination-item--page">
                  <a class="ais-Pagination-link page-number" aria-label="2" href="#">2</a>
                </li>
                <li class="ais-Pagination-item pagination-item ais-Pagination-item--page">
                  <a class="ais-Pagination-link page-number" aria-label="3" href="#">3</a>
                </li>
                <li class="ais-Pagination-item pagination-item ais-Pagination-item--page">
                  <a class="ais-Pagination-link page-number" aria-label="4" href="#">4</a>
                </li>
                <li class="ais-Pagination-item pagination-item ais-Pagination-item--page">
                  <a class="ais-Pagination-link page-number" aria-label="5" href="#">5</a>
                </li>
                <li class="ais-Pagination-item pagination-item ais-Pagination-item--page">
                  <a class="ais-Pagination-link page-number" aria-label="6" href="#">6</a>
                </li>
                <li class="ais-Pagination-item pagination-item ais-Pagination-item--page">
                  <a class="ais-Pagination-link page-number" aria-label="7" href="#">7</a>
                </li>
                <li class="ais-Pagination-item pagination-item ais-Pagination-item--nextPage">
                  <a class="ais-Pagination-link page-number" aria-label="Next" href="#">
                    <i class="ic i-angle-right"></i>
                  </a>
                </li>
              </ul>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { defineProps, toRefs, defineEmits, onMounted, ref } from "vue";
import { store } from "@/stores/store.js";
import { debounce } from "@/utils/util.js";
const state = store();
const posts = state.postsDic;
const props = defineProps({ showSearch: Boolean });
const { showSearch } = toRefs(props);
const emits = defineEmits(["close"]);
const closeSearchDialog = () => {
  emits("close", false);
};
// out close
onMounted(() => {
  const dialog = document.getElementById("search");
  const btn = document.getElementsByClassName("item search")[0];
  const content = document.getElementsByClassName("search-inner")[0];

  dialog.addEventListener("click", (e) => {
    emits("close", false);
  });
  btn.addEventListener("click", (e) => {
    e.stopPropagation();
  });
  content.addEventListener("click", (e) => {
    e.stopPropagation();
  });
});
const inputVal = ref("");
const searchResult = ref([]);
const query = () => {
  searchResult.value = [];
  const val = inputVal.value;
  for (const [key, value] of posts) {
    if (key.includes(val) || value.content.includes(val)) {
      searchResult.value.push(value);
    }
  }
};
const db = debounce(query, 500);

const searchForArticles = (inputValue) => {
  db();
};
</script>
<style lang="scss" scoped>
.show--search {
  transform: scale(1);
  opacity: 1;
  display: block !important;
}

.pagination .next:hover,
.pagination .page-number.current,
.pagination .page-number:hover,
.pagination .prev:hover {
  color: var(--grey-0);
  background-color: var(--color-young-blue);
  box-shadow: 0 0.125rem 0.75rem var(--color-young-blue);
  opacity: 0.9;
  border-radius: 0.625rem;
}

.pagination .next,
.pagination .page-number,
.pagination .prev,
.pagination .space {
  display: inline-block;
  margin: 0 0.5rem;
  padding: 0 0.75rem;
  position: relative;
  border-radius: 0.3125rem;
}

@media (max-width: 767px) {
  .pagination .next,
  .pagination .page-number,
  .pagination .prev,
  .pagination .space {
    margin: 0 0.3125rem;
  }
}

.pagination {
  width: 100%;
  padding: 1.25rem 3.125rem;
  text-align: center;
  display: inline-block;
  color: var(--grey-5);
}

@media (max-width: 767px) {
  .pagination {
    padding: 1.25rem 0.625rem;
  }
}

.pagination .next,
.pagination .page-number,
.pagination .prev {
  transition: all 0.2s ease-in-out 0s;
}

.pagination .space {
  margin: 0;
  padding: 0;
}

.pagination .prev {
  margin-left: 0;
}

.pagination .next {
  margin-right: 0;
}

.pagination .page-number.current:hover {
  box-shadow: 0 0 0.3125rem var(--primary-color);
}
</style>