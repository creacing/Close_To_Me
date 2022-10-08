<template>
  <div class="index wrap">
    <!-- <h2 class="divider">置顶文章</h2>
    <TopArticle />-->
    <!-- <h2 class="divider">精选分类</h2>
    <Types />
    <h2 class="divider">文章列表</h2>-->
    <ArticleList :articles="articles" />
  </div>
  <Pagination :pageNum="pageNum" />
</template>
<script setup>
// import TopArticle from '@/components/TopArticle.vue'
import Types from '@/components/Types.vue'
import ArticleList from '@/components/ArticleList.vue'
import Pagination from '@/components/Pagination.vue'
import { store } from "@/stores/store.js";
import { ref } from 'vue'
const state = store();
const posts = state.posts
const postLen = state.postLen
const articles = ref([])
const pageSize = 6
const pageNum = postLen / pageSize
let pageIndex = 0
articles.value = posts.slice(pageIndex * pageSize, pageIndex * pageSize + 6)
</script>


