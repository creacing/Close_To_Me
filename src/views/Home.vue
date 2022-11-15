<template>
  <div class="container">
    <ArticleList :articles="articles" />
  </div>
  <Pagination :pageNum="pageNum" @getCurIndex="getCurIndex" />
</template>
<script setup>
import ArticleList from "@/components/ArticleList.vue";
import Pagination from "@/components/Pagination.vue";
import { store } from "@/stores/store.js";
import { ref } from "vue";

const { posts, postLen, pageSize } = store();

const articles = ref([]);
const pageNum = postLen / pageSize;
let pageIndex = 1;


const initArticle = () => {
  articles.value = posts.slice(
    (pageIndex - 1) * pageSize,
    (pageIndex - 1) * pageSize + pageSize
  );
}


const getCurIndex = (pageIndex) => {
  articles.value = posts.slice(
    (pageIndex - 1) * pageSize,
    (pageIndex - 1) * pageSize + pageSize
  );
};


initArticle()
</script>
<style lang="scss" scoped>
</style>


