<template>
  <div class="index wrap">
    <h2 class="divider">置顶文章</h2>
    <TopArticle />
    <h2 class="divider">精选分类</h2>
    <Types />
    <h2 class="divider">文章列表</h2>
    <ArticleList />
  </div>
  <Pagination />
</template>
<script setup>
import TopArticle from '@/components/TopArticle.vue'
import Types from '@/components/Types.vue'
import ArticleList from '@/components/ArticleList.vue'
</script>


