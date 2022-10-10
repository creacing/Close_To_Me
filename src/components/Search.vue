<template>
  <div id="search" :class="[showSearch ? 'show--search' : '']" v-show="showSearch">
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
                找到 {{searchResult.length}} 条结果
                <span class="algolia-powered"></span>
                <hr />
              </span>
            </div>
          </div>
          <div id="search-hits">
            <div>
              <div class="ais-Hits">
                <ol class="ais-Hits-list">
                  <li class="ais-Hits-item item" v-for="res in searchResult" :key="res">
                    <RouterLink :to="`article${res.path}`">
                      <span>
                        {{res.tags.join(' ')}}
                        <i class="ic i-angle-right"></i>
                        {{res.title}}
                        <i class="ic i-angle-right"></i>
                        {{res.description}}
                      </span>
                      {{res.date}}
                    </RouterLink>
                  </li>
                </ol>
              </div>
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
import { RouterLink } from 'vue-router'
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

#search {
  position: fixed;
  background: var(--nav-morandi-bg);
  left: 0;
  top: 0;
  width: 100%;
  height: 100%;
  padding: 1.25rem;
  z-index: 999;
}

#search > .inner {
  border-radius: 0;
  height: 100%;
  margin: 0 auto;
  /* width: 43.75rem; */
  text-shadow: none;
}

@media (max-width: 767px) {
  #search > .inner {
    width: 100%;
  }
}

#search > .inner .close-btn,
#search > .inner .icon {
  color: var(--grey-5);
  font-size: 1.125rem;
  padding: 0 0.625rem;
}

#search > .inner .close-btn {
  cursor: pointer;
}

#search > .inner .close-btn:hover i {
  color: var(--grey-7);
}

#search > .inner .header {
  display: flex;
  background: var(--color-morandi-purple);
  padding: 0.5rem 1.5rem;
  margin-bottom: 1.25rem;
  font-size: 1.125em;
  align-items: center;
}

#search > .inner .search-input-container {
  flex-grow: 1;
}

#search > .inner .search-input-container form {
  padding: 0.125rem;
}

#search > .inner .search-input {
  background: 0 0;
  border: 0;
  outline: 0;
  width: 100%;
}

#search > .inner .search-input::-webkit-search-cancel-button {
  display: none;
}

#search .results {
  height: calc(100% - 6.25rem);
  padding: 1.875rem 1.875rem 0.3125rem;
  border-radius: 0.3125rem;
  background: var(--color-morandi-purple) url(../../public/images/search.png)
    no-repeat bottom right;
  color: var(--text-color);
}

#search .results .inner {
  position: relative;
  height: 100%;
  overflow: hidden;
}

#search .results hr {
  margin: 0.625rem 0;
}

.algolia-powered {
  float: right;
  background: url(../images/algolia_logo.svg) no-repeat;
  display: inline-block;
  height: 1.125rem;
  width: 4.25rem;
  margin: 0.5rem auto;
}

#search-hits {
  overflow-y: scroll;
  height: calc(100% - 8.125rem);
}

#search-hits ol {
  padding: 0;
}

#search-hits .item {
  margin: 0.9375rem 0;
}

#search-hits .item a {
  border-bottom: 0.0625rem dashed var(--grey-4);
  display: block;
  transition: all 0.2s ease-in-out 0s;
}

#search-hits .item span {
  font-size: 70%;
  display: block;
}

#search-hits .item span i {
  color: var(--grey-4);
  margin: 0 0.3125rem;
}

#search-pagination ul {
  padding: 0;
  margin: 1.25rem 0;
}

#search-pagination .pagination {
  opacity: 1;
  padding: 0;
}

#search-pagination .pagination-item {
  display: inline-block;
}

#search-pagination .page-number {
  transition: all 0.2s ease-in-out 0s;
}

#search-pagination .current .page-number {
  cursor: default;
}

#search-pagination .disabled-item {
  color: var(--grey-4);
  cursor: default;
}

#search-pagination .disabled-item .page-number:hover {
  color: var(--grey-4);
  background: 0 0;
  box-shadow: none;
}
</style>