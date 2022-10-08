<template>
  <div class="inner">
    <div id="main" class="pjax">
      <slot name="content"></slot>
    </div>
    <Sidebar v-if="switchSidebar" />
    <ArticleSidebar v-if="!switchSidebar" />
    <div class="dimmer"></div>
  </div>
</template>
<script setup>
import Pagination from "@/components/Pagination.vue";
import Sidebar from "@/components/Sidebar.vue";
import ArticleSidebar from "@/components/ArticleSidebar.vue";
import { useRoute } from "vue-router";
import { ref, watch } from 'vue'
const route = useRoute();
const switchSidebar = ref(true)
watch(() => route.path, (newPath, oldPath) => {
  switchSidebar.value = newPath.startsWith('/article/') ? false : true
}, { immediate: true });
</script>
<style scoped>
#main {
  min-height: 100vh;
}
</style>