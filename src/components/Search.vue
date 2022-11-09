<template>
  <div class="search pos-fix" :class="[showSearch ? 'search-show' : '']" v-show="showSearch">
    <div class="body">
      <div class="header">
        <span class="icon">
          <i class="ic i-search"></i>
        </span>
        <div class="search-input">
          <form role="search" novalidate>
            <input class="input" type="search" placeholder="文章搜索" autocomplete="off" autocorrect="off"
              autocapitalize="off" spellcheck="false" maxlength="512" @input="searchForArticles" v-model="inputVal" />
          </form>
        </div>
        <span class="close-btn" @click="closeSearchDialog">
          <i class="ic i-times-circle"></i>
        </span>
      </div>
      <div class="content">
        <span>找到 {{ searchResult.length }} 条结果</span>
        <hr />

        <ol class="result">
          <li class="item" v-for="res in searchResult" :key="res" @click="closeSearchDialog">
            <RouterLink :to="`article${res.path}`">
              <span>
                {{ res.title }}
                <i class="ic i-angle-right"></i>
                {{ res.date }}
              </span>
            </RouterLink>
          </li>
        </ol>
      </div>
    </div>
  </div>
</template>

<script setup>
import { defineProps, toRefs, defineEmits, onMounted, ref } from "vue";
import { store } from "@/stores/store.js";
import { debounce } from "@/utils/util.js";
import { RouterLink } from "vue-router";
const state = store();

const props = defineProps({ showSearch: Boolean });
const { showSearch } = toRefs(props);

const emits = defineEmits(["close"]);
const closeSearchDialog = () => {
  emits("close", false);
};

const posts = state.postsDic;
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

const searchForArticles = (inputValue) => { db(); };
</script>
<style lang="scss" scoped>
.search-show {
  display: block !important;
}


.search {
  background: var(--nav-bg);
  left: 0;
  top: 0;
  width: 40%;
  height: 100%;
  padding: 1.25rem;
  z-index: 1000;

  .body {
    height: 100%;
    margin: 0 auto;
    text-shadow: none;

    .header {
      display: flex;
      padding: 0.5rem 1.5rem;
      font-size: 1.125em;
      align-items: center;

      .search-input {
        flex-grow: 1;

        form {
          padding: 0.125rem;
        }
      }

      .close-btn,
      .icon {
        color: var(--grey-5);
        font-size: 1.125rem;
        padding: 0 0.625rem;
      }

      .close-btn {
        cursor: pointer;
      }

      .close-btn:hover i {
        color: var(--grey-7);
      }
    }

    .content {
      height: calc(100% - 6.25rem);
      padding: 1.875rem 1.875rem 0.3125rem;
      color: var(--text-color);
      position: relative;

      .result {
        overflow-y: scroll;
        height: 100%;

        .item {
          margin: 0.9375rem 0;

          a {
            transition: all 0.2s ease-in-out 0s;

            span {
              font-size: 90%;
              display: block;

              i {
                color: var(--grey-4);
                margin: 0 0.3125rem;
              }
            }
          }
        }
      }

      hr {
        margin: 0.625rem 0;
      }
    }
  }

  .body .input {
    background: 0 0;
    border: 0;
    outline: 0;
    width: 100%;
  }

  .body .input::-webkit-search-cancel-button {
    display: none;
  }
}

@media (max-width: 767px) {
  .search {
    width: 100%;
  }
}
</style>