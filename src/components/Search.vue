<template>
  <div
    id="search"
    :class="[showSearch ? 'show--search' : '']"
    v-show="showSearch"
    ref="searchDialog"
  >
    <div class="inner search-inner">
      <div class="header">
        <span class="icon"><i class="ic i-search"></i></span>
        <div class="search-input-container">
          <div class="ais-SearchBox">
            <form action="" role="search" class="ais-SearchBox-form" novalidate>
              <input
                class="ais-SearchBox-input search-input"
                type="search"
                placeholder="文章搜索"
                autocomplete="off"
                autocorrect="off"
                autocapitalize="off"
                spellcheck="false"
                maxlength="512"
              /><button
                class="ais-SearchBox-submit"
                type="submit"
                title="Submit the search query."
                hidden
              >
                <svg
                  class="ais-SearchBox-submitIcon"
                  width="10"
                  height="10"
                  viewBox="0 0 40 40"
                >
                  <path
                    d="M26.804 29.01c-2.832 2.34-6.465 3.746-10.426 3.746C7.333 32.756 0 25.424 0 16.378 0 7.333 7.333 0 16.378 0c9.046 0 16.378 7.333 16.378 16.378 0 3.96-1.406 7.594-3.746 10.426l10.534 10.534c.607.607.61 1.59-.004 2.202-.61.61-1.597.61-2.202.004L26.804 29.01zm-10.426.627c7.323 0 13.26-5.936 13.26-13.26 0-7.32-5.937-13.257-13.26-13.257C9.056 3.12 3.12 9.056 3.12 16.378c0 7.323 5.936 13.26 13.258 13.26z"
                  ></path>
                </svg></button
              ><button
                class="ais-SearchBox-reset"
                type="reset"
                title="Clear the search query."
                hidden
              >
                <svg
                  class="ais-SearchBox-resetIcon"
                  viewBox="0 0 20 20"
                  width="10"
                  height="10"
                >
                  <path
                    d="M8.114 10L.944 2.83 0 1.885 1.886 0l.943.943L10 8.113l7.17-7.17.944-.943L20 1.886l-.943.943-7.17 7.17 7.17 7.17.943.944L18.114 20l-.943-.943-7.17-7.17-7.17 7.17-.944.943L0 18.114l.943-.943L8.113 10z"
                  ></path>
                </svg>
              </button>
            </form>
          </div>
        </div>
        <span class="close-btn" @click="closeSearchDialog"
          ><i class="ic i-times-circle"></i
        ></span>
      </div>
      <div class="results">
        <div class="inner">
          <div id="search-stats"></div>
          <div id="search-hits"></div>
          <div id="search-pagination"></div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import {
  defineProps,
  toRefs,
  defineEmits,
  onMounted,
  nextTick,
  ref,
  getCurrentInstance,
} from "vue";
const props = defineProps({ showSearch: Boolean });
const { showSearch } = toRefs(props);
const emits = defineEmits(["close"]);
const closeSearchDialog = () => {
  emits("close", false);
};
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
</script>
<style lang="scss" scoped>
.show--search {
  transform: scale(1);
  opacity: 1;
  display: block !important;
}
</style>