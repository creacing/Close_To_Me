<template>
  <div id="search" :class="[showSearch ? 'show--search' : '']" v-show="showSearch">
    <div class="search--content">
      <div class="header">
        <span class="icon">
          <i class="ic i-search"></i>
        </span>
        <div class="search--input">
          <form role="search" novalidate>
            <input
              class="search-input"
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
        <span class="close-btn" @click="closeSearchDialog">
          <i class="ic i-times-circle"></i>
        </span>
      </div>
      <div class="results">
        <div class="results--content">
          <span>
            找到 {{searchResult.length}} 条结果
            <hr />
          </span>

          <ol id="search--res">
            <li class="item" v-for="res in searchResult" :key="res" @click="closeSearchDialog">
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
  const content = document.getElementsByClassName("search--content")[0];

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

#search > .search--content {
  border-radius: 0;
  height: 100%;
  margin: 0 auto;
  /* width: 43.75rem; */
  text-shadow: none;
}

@media (max-width: 767px) {
  #search > .search--content {
    width: 100%;
  }
}

#search > .search--content .close-btn,
#search > .search--content .icon {
  color: var(--grey-5);
  font-size: 1.125rem;
  padding: 0 0.625rem;
}

#search > .search--content .close-btn {
  cursor: pointer;
}

#search > .search--content .close-btn:hover i {
  color: var(--grey-7);
}

#search > .search--content .header {
  display: flex;
  background: var(--color-morandi-purple);
  padding: 0.5rem 1.5rem;
  margin-bottom: 1.25rem;
  font-size: 1.125em;
  align-items: center;
}

#search > .search--content .search--input {
  flex-grow: 1;
}

#search > .search--content .search--input form {
  padding: 0.125rem;
}

#search > .search--content .search-input {
  background: 0 0;
  border: 0;
  outline: 0;
  width: 100%;
}

#search > .search--content .search-input::-webkit-search-cancel-button {
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

#search .results .results--content {
  position: relative;
  height: 100%;
  overflow: hidden;
}

#search .results hr {
  margin: 0.625rem 0;
}

#search--res {
  overflow-y: scroll;
  height: calc(100% - 8.125rem);
}

#search--res ol {
  padding: 0;
}

#search--res .item {
  margin: 0.9375rem 0;
}

#search--res .item a {
  border-bottom: 0.0625rem dashed var(--grey-4);
  display: block;
  transition: all 0.2s ease-in-out 0s;
}

#search--res .item span {
  font-size: 70%;
  display: block;
}

#search--res .item span i {
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