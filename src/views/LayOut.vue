<template>
  <div class="inner">
    <Sidebar v-if="switchSidebar" />
    <Index v-if="!switchSidebar" :sideIndex="sideIndex" />
    <div id="main">
      <div class="g--animation g--content">
        <slot name="content"></slot>
      </div>
    </div>
  </div>
</template>
<script setup>
import Pagination from "@/components/Pagination.vue";
import Sidebar from "@/components/Sidebar.vue";
import Index from "@/components/Index.vue";
import { store } from '@/stores/store.js'

import { useRoute } from "vue-router";
import { ref, watch } from "vue";
const route = useRoute();
const switchSidebar = ref(true);
const sideIndex = ref([])
const state = store()

watch(
  () => route.path,
  (newPath, oldPath) => {
    switchSidebar.value = newPath.startsWith("/article/") ? false : true;
  },
  { immediate: true }
);

watch(
  () => state.sideIndex,
  (newIndex, oldIndex) => {
    sideIndex.value = newIndex
  },
  { immediate: true }
);
</script>
<style scoped>
#main {
  min-height: 100vh;
  flex: auto;
}
</style>